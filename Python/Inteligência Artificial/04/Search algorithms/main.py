from heapq import heappop, heappush

# Data
romenia = {
    "Arad": {"Zerind": 75, "Timisoara": 118, "Sibiu": 140},
    "Zerind": {"Oradea": 71, "Arad": 75},
    "Timisoara": {"Lugoj": 111, "Arad": 118},
    "Lugoj": {"Timisoara": 111, "Mehadia": 70},
    "Mehadia": {"Lugoj": 70, "Drobeta": 75},
    "Drobeta": {"Mehadia": 75, "Craiova": 120},
    "Craiova": {"Rimnicu Vilcea": 146, "Pitesti": 138, "Drobeta": 120,},
    "Rimnicu Vilcea": {"Sibiu": 80, "Pitesti": 97, "Craiova": 146,},
    "Sibiu": {"Rimnicu Vilcea": 80, "Oradea": 151, "Fagaras": 99, "Arad": 140,},
    "Oradea": {"Zerind": 71, "Sibiu": 151},
    "Fagaras": {"Sibiu": 99, "Bucharest": 211},
    "Pitesti": {"Rimnicu Vilcea": 97, "Craiova": 138, "Bucharest": 101},
    "Bucharest": {"Urziceni": 85, "Pitesti": 101, "Giurgiu": 90, "Fagaras": 211},
    "Giurgiu": {"Bucharest": 90},
    "Urziceni": {"Vaslui": 142, "Hirsova": 98, "Bucharest": 85,},
    "Hirsova": {"Urziceni": 98, "Eforie": 86},
    "Eforie": {"Hirsova": 86},
    "Vaslui": {"Urziceni": 142, "Iasi": 92},
    "Iasi": {"Vaslui": 92, "Neamt": 87},
    "Neamt": {"Iasi": 87}
}

G0 = {
    'S': ['d', 'e', 'p'],
    'a': [],
    'b': ['a'],
    'c': ['a'],
    'd': ['b', 'c', 'e'],
    'e': ['h', 'r'],
    'f': ['c', 'g'],
    'g': [],
    'h': ['p', 'q'],
    'p': ['q'],
    'q': [],
    'r': ['f']
}

G1 = {
    'S': {'d': 3, 'e': 9, 'p': 1},
    'a': {},
    'b': {'a': 2},
    'c': {'a': 2},
    'd': {'b': 1, 'c': 8, 'e': 2},
    'e': {'h': 8, 'r': 2},
    'f': {'c': 3, 'g': 2},
    'g': {},
    'h': {'p': 4, 'q': 4},
    'p': {'q': 15},
    'q': {},
    'r': {'f': 1}
}

# Função sucessora (estratégia de exploração)
def dfs(adj_list, start, goal):
    visited = [] # visitados
    fringe = [start] # fronteira (pilha com candidatos)
    path = [[start]] # path de resposta

    while fringe:
        cur_node = fringe.pop() # em visitação
        cur_path = path.pop() # caminho atual até o em visitação

        # visita o nó
        if cur_node not in visited:
            visited.append(cur_node)

            # nó é final
            if cur_node == goal:
                return cur_path
            else:
                for neighbor in sorted(adj_list[cur_node], reverse=True):
                    if neighbor not in visited:
                        # adiciona aos pendentes (fronteira)
                        fringe.append(neighbor)
                        # adiciona caminho
                        path.append(cur_path + [neighbor])
    
    return None


def bfs(adj_list, start, goal):
    visited = [] # visitados
    fringe = [start] # fronteira (pilha com candidatos)
    path = [[start]] # path de resposta

    while fringe:
        cur_node = fringe.pop(0) # em visitação
        cur_path = path.pop(0) # caminho atual até o em visitação

        # visita o nó
        if cur_node not in visited:
            visited.append(cur_node)

            # nó é final
            if cur_node == goal:
                return cur_path
            else:
                for neighbor in sorted(adj_list[cur_node], reverse=False):
                    if neighbor not in visited:
                        # adiciona aos pendentes (fronteira)
                        fringe.append(neighbor)
                        # adiciona caminho
                        path.append(cur_path + [neighbor])
    
    return None


# Função sucessora (estratégia de exploração)
def ucs(adj_list, start, goal):
    visited = [] # visitados
    fringe = [(0, start)] # fronteira (pilha com candidatos) com prioridades
    path = [(0, [start])] # path de resposta

    while fringe:
        cur_cost, cur_node = heappop(fringe) # em visitação
        cur_path = heappop(path)[1] # caminho atual até o em visitação

        # visita o nó
        if cur_node not in visited:
            visited.append(cur_node)

            # nó é final
            if cur_node == goal:
                return cur_path
            else:
                for neighbor, cost in adj_list[cur_node].items():
                    if neighbor not in visited:
                        # adiciona aos pendentes (fronteira)
                        heappush(fringe, (cur_cost + cost, neighbor))
                        # adiciona caminho
                        heappush(path, (cur_cost + cost, cur_path + [neighbor]))
    
    return None


if __name__ == "__main__":
    print(dfs(G0, "S", "g"))
    print(bfs(G0, "S", "g"))
    print(ucs(romenia, "Arad", "Bucharest"))
