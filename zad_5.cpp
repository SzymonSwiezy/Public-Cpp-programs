#include<iostream>
#include <vector>
#include <string>
class Tree
{
private:
    std::string name;
    uint32_t treeSize = 0;
    std::string nodeNumber;
    std::vector<Tree *> node;

public:
    Tree(std::string name) : name(name){};

    Tree *AddSub(std::string name)
    {
        Tree *newNode = new Tree(name);
        newNode->name = name;
        this->node.push_back(newNode);
        return newNode;
    }

    void printTree(int deep, bool addNumber)
    {
        {
            if (addNumber)
                std::cout << nodeNumber;
            for (int i = 0; i < deep; i++)
                std::cout << "\t";
            std::cout << name << std::endl;
            for (int i = 0; i < node.size(); i++)
            {
                if (addNumber)
                    node.at(i)->nodeNumber = this->nodeNumber + std::to_string(i + 1) + '.';
                node.at(i)->printTree(deep + 1, addNumber);
            }
        }
    }

    uint32_t GetSubCount()
    {
        uint32_t res = 0;
        for (int i = 0; i < node.size(); i++)
            res++;
        return res;
    }

    uint32_t GetAllSubCount()
    {
        treeSize = GetSubCount();
        for (int i = 0; i < node.size(); i++)
            treeSize = treeSize + node.at(i)->GetAllSubCount();
        return treeSize;
    }

    void Del(int a)
    {
        for (int i = 0; i < node.size(); i++)
        {
            if (i == a)
                node.erase(node.begin() + i);
        }
    }

    friend void Delete(Tree *node);
};

void Delete(Tree *node)
{
    for (int i = 0; i < node->node.size(); i++)
        Delete(node->node[i]);
    node->node.clear();
}

int main()
{

    std::cout << "--------- ZADANIE 5 --------- \n";

    Tree *root = new Tree("root tree");

    Tree *galaz1 = root->AddSub("galaz 1");

    Tree *galaz2 = root->AddSub("galaz 2");

    Tree *galaz3 = root->AddSub("galaz 3");

    Tree *galaz1_1 = galaz1->AddSub("galaz 1.1");

    Tree *galaz2_1 = galaz2->AddSub("galaz 2.1");

    Tree *galaz2_2 = galaz2->AddSub("galaz 2.2");

    Tree *galaz2_1_2 = galaz2_1->AddSub("galaz 2.1.1");

    root->printTree(0, true);
    root->Del(1);
    root->printTree(0, true);
    Delete(root);
    return 0;
}