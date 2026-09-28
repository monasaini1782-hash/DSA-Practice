#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <chrono>
using namespace std;
using namespace chrono;

struct Node
{
    char ch;
    int freq;
    Node *left;
    Node *right;

    Node(char c, int f)
    {
        ch = c;
        freq = f;
        left = NULL;
        right = NULL;
    }
};

struct Compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->freq > b->freq;
    }
};

void printCodes(Node *root, string code)
{
    if (root == NULL)
        return;

    if (root->ch != '#')
        cout << root->ch << " : " << code << endl;

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main()
{
    int n;

    cout << "Enter number of characters: ";
    cin >> n;

    priority_queue<Node *, vector<Node *>, Compare> pq;

    cout << "Enter character and frequency:\n";

    for (int i = 0; i < n; i++)
    {
        char ch;
        int freq;

        cin >> ch >> freq;

        pq.push(new Node(ch, freq));
    }

    auto start = high_resolution_clock::now();

    while (pq.size() > 1)
    {
        Node *left = pq.top();
        pq.pop();

        Node *right = pq.top();
        pq.pop();

        Node *parent =
            new Node('#', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        pq.push(parent);
    }

    Node *root = pq.top();

    auto end = high_resolution_clock::now();

    cout << "\n========== HUFFMAN CODES ==========\n";

    printCodes(root, "");

    cout << "\nExecution Time: "
         << duration_cast<nanoseconds>(end - start).count()
         << " ns\n";

    cout << "\nTime Complexity:\n";
    cout << "Best Case    : O(n log n)\n";
    cout << "Average Case : O(n log n)\n";
    cout << "Worst Case   : O(n log n)\n";

    return 0;
}