#include <iostream>
#include <vector>

class Tree
{

private:
    std::string name;
    uint32_t treeSize = 0;
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

    void printTree(int deep)
    {
        for (int i = 0; i < deep; i++)
            std::cout << "\t";
        std::cout << name << std::endl;
        for (int i = 0; i < node.size(); i++)
            node.at(i)->printTree(deep + 1);
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
    std::cout << "--------- ZADANIE 4 --------- \n";
    Tree *root = new Tree("root tree");

    Tree *galaz1 = root->AddSub("galaz 1");

    Tree *galaz2 = root->AddSub("galaz 2");

    Tree *galaz3 = root->AddSub("galaz 3");

    Tree *galaz1_1 = galaz1->AddSub("galaz 1.1");

    Tree *galaz2_1 = galaz2->AddSub("galaz 2.1");

    Tree *galaz2_2 = galaz2->AddSub("galaz 2.2");

    Tree *galaz2_1_2 = galaz2_1->AddSub("galaz 2.1.1");

    root->printTree(0);

    uint32_t ileDzieciRoota = root->GetSubCount();
    uint32_t ileDzieciGalaz1 = galaz1->GetSubCount();
    uint32_t ileWszystkichGalezi = root->GetAllSubCount();
    std::cout << "\nileDzieciRoota\n"
              << ileDzieciRoota
              << "\nileDzieciGalaz1\n"
              << ileDzieciGalaz1
              << "\nileWszystkichGalezi\n"
              << ileWszystkichGalezi << std::endl;
    root->Del(1);
    root->printTree(0);
    uint32_t ileDzieciRoota_v2 = root->GetSubCount();
    uint32_t ileWszystkichGalezi_v2 = root->GetAllSubCount();
    std::cout << "\nileDzieciRoota_v2\n"
              << ileDzieciRoota_v2
              << "\nileWszystkichGalezi_v2\n"
              << ileWszystkichGalezi_v2 << std::endl;
    Delete(root);
    root->printTree(0);
    return 0;
}