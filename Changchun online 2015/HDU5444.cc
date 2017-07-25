#include <iostream>
#include <cstdio>

struct node{
	int num;
	node * western;
	node * eastern;
};

void maketree(node * root, int data) {
	if(root -> num < data) {
		if(root -> western == NULL) {
			node *p = new node;
			p -> num = data;
			p -> western = NULL;
			p -> eastern = NULL;
			root -> western = p;
		} else {
			maketree(root -> western, data);
		}
	} else {
		if(root -> eastern == NULL) {
			node *p = new node;
			p -> num = data;
			p -> western = NULL;
			p -> eastern = NULL;
			root -> eastern = p;
		} else {
			maketree(root -> eastern, data);
		}
	}
}

void query(node * root, int elve) {
	if(elve == root -> num) {
		std::cout << "\n";
	} else if(elve > root -> num) {
		std::cout << "W";
		query(root -> western, elve);
	} else {
		std::cout << "E";
		query(root -> eastern, elve);
	}
}

int main(int argc, char *argv[]) {  
	std::ios::sync_with_stdio(false);  
	int t;
	std::cin >> t;
	while (t--) {
		int n;
		std::cin >> n;
		node *root = new node;
		root -> western = NULL;
		root -> eastern = NULL;
		int temp_num;
		std::cin >> temp_num;
		root -> num = temp_num;
		for(int i = 0; i < n-1; i++) {
			std::cin >> temp_num;
			maketree(root, temp_num);
		}
		int q;
		std::cin >> q;
		for(int i = 0; i < q; i++) {
			int id;
			std::cin >> id;
			query(root, id);
		}
	}
	return 0;
}