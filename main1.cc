#include <iostream>
#include <vector>

#include <cstdio>


class CasketOfStarEasy {
public:
  int maxEnergy(std::vector<int> weight);

private:
  int search(std::vector<int> weight);
};

int CasketOfStarEasy::maxEnergy(std::vector<int> weight)
{
  return search(weight);
}

int CasketOfStarEasy::search(std::vector<int> weight)
{
  int r = 0;

  for (int i = 1; i < weight.size() - 1; i ++) {
    std::vector<int> w;

    for (int j = 0; j < weight.size(); j ++)
      if (j != i)
	w.push_back(weight[j]);

    r = std::max(search(w) + weight[i-1] * weight[i+1], r);
  }

  return r;
}

int main(int argc, char** argv)
{
  std::vector<int> weight;

  int i;
  
  while (fscanf(stdin, "%d", &i) == 1)
    weight.push_back(i);

  std::cout << CasketOfStarEasy().maxEnergy(weight) << std::endl;
}
