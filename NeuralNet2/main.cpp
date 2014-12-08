#include <iostream>
#include <vector>
#include <assert.h>
#include <math.h>

using namespace std;

// Structure connection
struct Connection
{
	double weight;
	double deltaWeight;
};

// Class Neuron
class Neuron
{
public:
	Neuron(unsigned numOutputs);

private:
	static double randomWeight() { return rand() / double(RAND_MAX); }
	double m_outputVals;
	vector<Connection> m_outputWeights;
};

Neuron::Neuron(unsigned numOutputs)
{
	for (unsigned c = 0; c < numOutputs; ++c)
	{
		m_outputWeights.push_back(Connection());
		m_outputWeights.back().weight = randomWeight();
	}
}

// Type Layer
typedef vector<Neuron> Layer;

// Class Net
class Net
{
public:
	Net(const vector<unsigned> topology);
	void feedForward(const vector <double> &inputVals);
	void backProp(const vector <double> &targetVals);
	void getResults(vector<double> &resultVals) const;
	void toCommit(); 

private:
	vector<Layer> m_layers; // m_layers[layerNum][neuronNum]
};

void Net::feedForward(const vector <double> &inputVals)
{
//	assert(inputVals.size == m_layers[0].size() - 1);

	for (unsigned i = 0; i < inputVals.size(); ++i)
	{
//		m_layers[0][i].setOutputVal(inputVals[i]);
	}

	// Forward propagate
}

Net::Net(const vector <unsigned> topology)
{
	unsigned numLayers = topology.size();
	for (unsigned layerNum = 0; layerNum < numLayers; ++layerNum)
	{
		m_layers.push_back(Layer());
		unsigned numOutputs = layerNum == topology.size() - 1 ? 0 : topology[layerNum + 1];

		for (unsigned neuronNum = 0; neuronNum <= topology[layerNum]; ++neuronNum)
		{
			m_layers.back().push_back(Neuron(numOutputs));
			cout << "Made a Neuron!" << endl;
		}
	}
}

void main()
{
	vector<unsigned> topology;
	topology.push_back(3);
	topology.push_back(2);
	topology.push_back(1);
	Net myNet(topology);

	/*
	vector<double> inputVals;
	myNet.feedForward(inputVals);
	
	vector<double> targetVals;
	myNet.backProp(targetVals);

	vector<double> resultVals;
	myNet.getResults(resultVals);
	*/
}