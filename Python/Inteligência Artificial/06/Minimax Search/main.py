import numpy as np


from typing import Self


class Node:
    
    def __init__(self, utility:float=None):
        self.utility = utility
        self.children = []
    

    def add_child(self, child:Self):
        self.children.append(child)
    

    def is_terminal(self):
        return len(self.children) == 0


    def get_utility(self):
        return self.utility
    

    def get_children(self):
        return self.children


def minimax(node:Node, depth:int=1):
    is_agent_max = depth % 2 == 1

    if node.is_terminal():
        return node.get_utility()
    elif is_agent_max:
        return max_value(node, depth)
    else:
        return min_value(node, depth)


# Recursively  search for the biggest value of the successors of a node
def max_value(node:Node, depth:int) -> float:
    value = -np.inf
    for successor in node.get_children():
        value = max(value, minimax(successor, depth + 1))
    return value


# Recursively  search for the smallest value of the successors of a node
def min_value(node:Node, depth:int) -> float:
    value = np.inf
    for successor in node.get_children():
        value = min(value, minimax(successor, depth + 1))
    return value


if __name__ == "__main__":
    # Game tree 1
    A = Node()
    B = Node()
    C = Node()
    D = Node(2)
    E = Node(7)
    F = Node(1)
    G = Node(8)

    A.add_child(B)
    A.add_child(C)
    B.add_child(D)
    B.add_child(E)
    C.add_child(F)
    C.add_child(G)

    result = minimax(A)
    print(f"The best possible result is {result}")


    # Game tree 2
    A = Node()
    B = Node()
    C = Node()
    D = Node()
    E = Node()
    F = Node()
    G = Node()
    H = Node(5)
    I = Node(2)
    J = Node(1)
    K = Node(3)
    L = Node(6)
    M = Node(2)
    N = Node(0)
    O = Node(7)

    A.add_child(B)
    A.add_child(C)
    B.add_child(D)
    B.add_child(E)
    C.add_child(F)
    C.add_child(G)
    D.add_child(H)
    D.add_child(I)
    E.add_child(J)
    E.add_child(K)
    F.add_child(L)
    F.add_child(M)
    G.add_child(N)
    G.add_child(O)

    result = minimax(A)
    print(f"The best possible result is {result}")
