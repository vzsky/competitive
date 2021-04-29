// Genetic Algorithm (not a good one but yeah)
#include<bits/stdc++.h>
using namespace std;

const int POP_SIZE = 100; // even
const int CH_LEN = 300; 
const double CROSSOVER_PROB = 0.7;
const double MUTATION_PROB = 0.0001;
const int inf = 999;
const int GEN_LIM = 100;

/*
  gene index
  0 - 9 : 0 - 9
  10 : +
  11 : -
  12 : *
  13 : /
  14 - 15 : ERROR
*/

struct CH {
  string bits;
  double fitness;
  bool operator < (const CH & o) const {
    return fitness < o.fitness;
  }
} pop[POP_SIZE+5], newpop[POP_SIZE+5];

double ran01 () { return ((double)rand()/((double)RAND_MAX+1)); } // [0-1)
bool withProb (double p) { return ran01() < p; } 
int bitsToNumber (string bits) { return bits[3] + 2*bits[2] + 4*bits[1] + 8*bits[0] - 15*'0'; }

string parseBits (string bits) {
  string result = "";
  bool lastIsNum = false;
  for (int i = 0; i < bits.size(); i+=4) {
    string now = ""; 
    for (int j = 0; j < 4; j++) now += bits[i+j];
    int gene = bitsToNumber(now);
    if (!lastIsNum and gene >= 0 and gene <= 9) {
      result += (gene+'0');
      lastIsNum = true;
    }
    else if (lastIsNum and gene >= 10 and gene <= 13) {
      if (gene == 10) result += '+';
      if (gene == 11) result += '-';
      if (gene == 12) result += '*';
      if (gene == 13) result += '/';
      lastIsNum = false;
    }
  }
  if (!lastIsNum) result.pop_back();
  return result;
}

string GetRandomBits(int len) {
  string s = "";
  for (int i = 0; i < len; i++) s += withProb(0.5)?'1':'0';
  return s;
}

double calculate (string s) {
  double result = 0;
  result += s[0]-'0';
  for (int i = 1; i < s.size(); i+=2) {
    if (s[i] == '+') result += (s[i+1]-'0');
    if (s[i] == '-') result -= (s[i+1]-'0');
    if (s[i] == '*') result *= (s[i+1]-'0');
    if (s[i] == '/') result /= (s[i+1]-'0');
  }
  if (isnan(result)) return 0;
  return result;
}

double getFitness (string bits, double target) {
  string character = parseBits(bits);
  double result = calculate(character);
  // if (result == target) return inf;
  return 1.0/fabs(result-target);
}

string roulette (double total) {
  double goal = (ran01() * total);
	double pos = 0.0;
	for (int i = 0; i < POP_SIZE; i++) {
		pos += pop[i].fitness;
		if (pos >= goal) return pop[i].bits;
	}
  sort(pop, pop+POP_SIZE);
  return pop[0].bits;
}

pair<string,string> Crossover (string p1, string p2) {
  if (withProb(CROSSOVER_PROB)) {
    int crossPoint = (int)(ran01() * CH_LEN);
    string t1 = p1.substr(0, crossPoint) + p2.substr(crossPoint, CH_LEN);
    string t2 = p2.substr(0, crossPoint) + p1.substr(crossPoint, CH_LEN);
    return {t1, t2};		  
  }
  return {p1, p2};
} 

void Mutate (string &bits) {
	for (int i = 0; i < bits.size(); i++) if (withProb(MUTATION_PROB)) {
		bits[i] = (bits[i]-'0')^1+'0';
	}
}

void ga(){
  cout << "Input target Number" << endl;
  double target; cin >> target;

  // random population
  for (int i = 0; i < POP_SIZE; i++) {
    pop[i].bits	  = GetRandomBits(CH_LEN);
    pop[i].fitness = 0.0;
  }

  int genCnt = 0;
  bool found = false;

  while (!found) {

    double TotalFitness = 0;
    
    // getFitness
    for (int i = 0; i < POP_SIZE; i++) {
      pop[i].fitness = getFitness(pop[i].bits, target);
      TotalFitness += pop[i].fitness;
		}

    cout << "generation " << genCnt << ", avg fitness is " << TotalFitness/POP_SIZE << endl;
    if (genCnt == GEN_LIM) break;

    // if found answer;
    for (int i = 0; i < POP_SIZE; i++) {
      if (pop[i].fitness >= inf) {
        cout << "Solution found in " << genCnt << " generations!" << endl;
        cout << parseBits(pop[i].bits) << endl << endl;
        found = true;
        return;
      }
    }

    for (int i = 0; i < POP_SIZE; i+=2) {
      string parent1 = roulette(TotalFitness), parent2 = roulette(TotalFitness);
      auto offs = Crossover(parent1, parent2);
      string off1 = offs.first;
      string off2 = offs.second;

      Mutate(off1);
      Mutate(off2);

      newpop[i].bits = off1;
      newpop[i].fitness = 0;
      newpop[i+1].bits = off2;
      newpop[i+1].fitness = 0;
    }

    for (int i = 0; i < POP_SIZE; i++) {
      pop[i] = newpop[i];
    }

    genCnt++;
  }
  cout << "No solution within " << genCnt << " generations" << endl;
}

int main () {
  srand(time(NULL));
  ga();
}