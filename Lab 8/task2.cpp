#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

class Combatant {
public:
    string name;
    int health;
    int attack;

    Combatant(string n = "", int h = 0, int a = 0)
        : name(n), health(h), attack(a) {}
};

class Node {
public:
    Combatant c;
    Node* left;
    Node* right;

    Node(Combatant combatant) {
        c = combatant;
        left = right = NULL;
    }
};

class BST {
public:
    Node* root;

    BST() { root = NULL; }

    Node* insert(Node* root, Combatant c) {
        if (root == NULL)
            return new Node(c);
        if (c.name < root->c.name)
            root->left = insert(root->left, c);
        else
            root->right = insert(root->right, c);
        return root;
    }

    void insert(Combatant c) {
        root = insert(root, c);
    }

    Node* findMin(Node* node) {
        while (node && node->left != NULL)
            node = node->left;
        return node;
    }

    Node* remove(Node* root, string name) {
        if (root == NULL) return root;

        if (name < root->c.name)
            root->left = remove(root->left, name);
        else if (name > root->c.name)
            root->right = remove(root->right, name);
        else {
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->c = temp->c;
            root->right = remove(root->right, temp->c.name);
        }
        return root;
    }

    void remove(string name) {
        root = remove(root, name);
    }

    bool isEmpty() {
        return root == NULL;
    }

    Node* getFrontline() {
        return findMin(root);
    }

    void display(Node* node) {
        if (node == NULL) return;
        display(node->left);
        cout << setw(10) << node->c.name << " (HP: " << node->c.health << ") ";
        display(node->right);
    }

    void displayTeam() {
        display(root);
        cout << endl;
    }
};

class BattleQuest {
private:
    BST playerTeam;
    BST enemyTeam;

public:
    BattleQuest() {
        srand(time(0));
        initializeTeams();
    }

    void initializeTeams() {
        playerTeam.insert(Combatant("HeroA", 30, 8));
        playerTeam.insert(Combatant("HeroB", 35, 7));
        playerTeam.insert(Combatant("HeroC", 25, 9));
        playerTeam.insert(Combatant("HeroD", 40, 6));
        playerTeam.insert(Combatant("HeroE", 20, 10));

        enemyTeam.insert(Combatant("Orc", 30, 7));
        enemyTeam.insert(Combatant("Goblin", 25, 6));
        enemyTeam.insert(Combatant("Troll", 35, 8));
        enemyTeam.insert(Combatant("Vampire", 40, 9));
        enemyTeam.insert(Combatant("Wraith", 28, 7));
    }

    void displayTeams() {
        cout << "\n===== Player Team =====" << endl;
        playerTeam.displayTeam();
        cout << "===== Enemy Team =====" << endl;
        enemyTeam.displayTeam();
        cout << "========================\n";
    }

    void attack(Node* attacker, Node* defender, BST& defenderTeam) {
        int damage = attacker->c.attack + (rand() % 5);
        defender->c.health -= damage;

        cout << attacker->c.name << " attacks " << defender->c.name
             << " for " << damage << " damage!" << endl;

        if (defender->c.health <= 0) {
            cout << defender->c.name << " has been defeated!" << endl;
            defenderTeam.remove(defender->c.name);
        } else {
            cout << defender->c.name << " now has " << defender->c.health << " HP left.\n";
        }
    }

    void startBattle() {
        int round = 1;

        cout << "\n=== BattleQuest: BST Arena Begins! ===\n";

        while (!playerTeam.isEmpty() && !enemyTeam.isEmpty()) {
            cout << "\n------------ Round " << round << " ------------" << endl;
            displayTeams();

            Node* playerFront = playerTeam.getFrontline();
            Node* enemyFront = enemyTeam.getFrontline();

            if (playerFront && enemyFront) {
                cout << "\nPlayer Turn:\n";
                attack(playerFront, enemyFront, enemyTeam);
            }

            if (enemyTeam.isEmpty()) {
                cout << "\nAll enemies defeated! Player wins the battle!\n";
                break;
            }

            playerFront = playerTeam.getFrontline();
            enemyFront = enemyTeam.getFrontline();

            if (playerFront && enemyFront) {
                cout << "\nEnemy Turn:\n";
                attack(enemyFront, playerFront, playerTeam);
            }

            if (playerTeam.isEmpty()) {
                cout << "\nAll heroes defeated! Enemies win the battle!\n";
                break;
            }

            round++;
        }

        cout << "\n===== Battle Over =====\n";
        displayTeams();
    }
};

int main() {
    BattleQuest game;
    game.startBattle();
    return 0;
}