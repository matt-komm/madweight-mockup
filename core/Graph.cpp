#include "Graph.hpp"


Graph::Graph()
{


}

Graph::~Graph()
{

}

void Graph::addNode(Node* node)
{
    //std::cout<<"adding node"<<std::endl;
    Leaf* leaf = new Leaf();
    this->_setupLeaf(leaf,node);

    _leafs.push_back(leaf);
}

void Graph::_setupLeaf(Leaf* leaf, Node* node)
{

    leaf->owner=node;
    for (unsigned int ivar = 0; ivar<node->getOutputSize();++ivar)
    {
        Variable* output = node->getOutput(ivar);
        const std::vector<Variable*> children = output->getChildren();
        for (unsigned int ichild=0; ichild<children.size();++ichild)
        {
            Edge* edge = new Edge();
            edge->target=children[ichild]->getOwner();

            //---------------------------------------------------------------------------------------------
            //WARNING: already existing Leafs with a connection to this one are unaware of the connection!!!
            //edge->leaf=_findLeaf(edge->target);
            //---------------------------------------------------------------------------------------------

            edge->name=output->getName()+"->"+children[ichild]->getName();
            leaf->out.push_back(edge);
            //std::cout<<"out: "<<edge->name<<std::endl;
        }
    }
    for (unsigned int ivar = 0; ivar<node->getInputSize();++ivar)
    {
        const Variable* input = node->getInput(ivar);
        if (input->hasParent())
        {
            Edge* edge = new Edge();
            edge->target=input->getParent()->getOwner();

            //---------------------------------------------------------------------------------------------
            //WARNING: already existing Leafs with a connection to this one are unaware of the connection!!!
            //edge->leaf=_findLeaf(edge->target);
            //---------------------------------------------------------------------------------------------

            edge->name=input->getParent()->getName()+"->"+input->getName();
            leaf->in.push_back(edge);
            //std::cout<<"in: "<<edge->name<<std::endl;
        }
    }
}

Graph::Leaf* Graph::_findLeaf(Node* node)
{
    for (unsigned int i=0; i<_leafs.size();++i)
    {
        if (node==_leafs[i]->owner)
        {
            return _leafs[i];
        }
    }
    return 0;
}

void Graph::setupGraphConnections()
{
	for (unsigned int ileaf=0; ileaf<_leafs.size();++ileaf)
	{
		Leaf* leaf = _leafs[ileaf];
		for (unsigned int iedge=0; iedge<leaf->out.size(); ++iedge)
		{
			Edge* edge = leaf->out[iedge];
			edge->leaf=this->_findLeaf(edge->target);
		}
		for (unsigned int iedge=0; iedge<leaf->in.size(); ++iedge)
		{
			Edge* edge = leaf->in[iedge];
			edge->leaf=this->_findLeaf(edge->target);
		}
	}
}

void Graph::sort()
{

    std::vector<Leaf*> sorted;
    std::vector<Leaf*> _noIncommingEdges;
    std::vector<Leaf*> rest;
    for (unsigned int i = 0; i<_leafs.size();++i)
    {
        if (_leafs[i]->in.size()==0)
        {
            _noIncommingEdges.push_back(_leafs[i]);
        }
        else
        {
            rest.push_back(_leafs[i]);
        }
    }

    while (_noIncommingEdges.size()>0)
    {
        Leaf* leaf = _noIncommingEdges.back();
        _noIncommingEdges.pop_back();
        sorted.push_back(leaf);
        for (unsigned int i = 0; i < rest.size();)
        {
            Leaf* child = rest[i];
            for (unsigned int j=0; j<child->in.size();)
            {
                if (child->in[j]->target==leaf->owner)
                {
                    child->in.erase(child->in.begin()+j);
                }
                else
                {
                    ++j;
                }
            }
            if (child->in.size()==0)
            {
                _noIncommingEdges.push_back(child);
                rest.erase(rest.begin()+i);
            }
            else
            {
                ++i;
            }
        }
    }
    if (rest.size()>0)
    {
        throw std::string("graph contains cycles");
    }
    _sortedNodes.clear();
    for (unsigned int i=0; i<sorted.size(); ++i)
    {
        _sortedNodes.push_back(sorted[i]->owner);
    }
}

void Graph::executeAll()
{
    if (_sortedNodes.size()==_leafs.size())
    {
        for (unsigned int i = 0; i < _sortedNodes.size(); ++i)
        {
            _sortedNodes[i]->execute();
            _sortedNodes[i]->updateOutput();
        }
    }
}

std::vector<Node*> Graph::getSortedList()
{
    return _sortedNodes;
}

