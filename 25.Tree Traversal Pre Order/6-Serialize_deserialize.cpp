#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

// TreeNode definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} 
};

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null"; // Base case

        // Preorder traversal: Root → Left → Right
        return to_string(root->val) + "," + serialize(root->left) + "," + serialize(root->right);
    }

    // Helper function to split string into a vector of values
    TreeNode* deserializeHelper(vector<string>& nodes, int& index) {
        if (index >= nodes.size() || nodes[index] == "null") {
            index++;
            return nullptr;
        }

        // Create a new node
        TreeNode* root = new TreeNode(stoi(nodes[index++]));

        // Recursively build left and right subtrees
        root->left = deserializeHelper(nodes, index);
        root->right = deserializeHelper(nodes, index);

        return root;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nodes;
        stringstream ss(data);
        string node;

        // Split the string by comma
        while (getline(ss, node, ',')) {
            nodes.push_back(node);
        }

        int index = 0; // Pointer to track position in nodes vector
        return deserializeHelper(nodes, index);
    }
};

// Helper function to print inorder traversal of the tree
void printInorder(TreeNode* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

// Driver code to test serialization and deserialization
int main() {
    Codec codec;

    // Constructing a sample tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    // Serialize the tree
    string serializedData = codec.serialize(root);
    cout << "Serialized Tree: " << serializedData << endl;

    // Deserialize the string back to tree
    TreeNode* deserializedRoot = codec.deserialize(serializedData);

    // Print inorder traversal of deserialized tree
    cout << "Inorder Traversal of Deserialized Tree: ";
    printInorder(deserializedRoot);
    cout << endl;

    return 0;
}
