from collections import defaultdict

class DFSGraphTraversal:
    def __init__(self):
        self.graph = defaultdict(list)

    #添加顶点
    def add_vertex(self, vertex):
        if vertex not in self.graph:
            self.graph[vertex] = []

    #添加边
    def add_edge(self, v1, v2):
        if v1 not in self.graph:
            self.add_vertex(v1)
        if v2 not in self.graph:
            self.add_vertex(v2)

        self.graph[v1].append(v2)


    def dfs(self, start_vertex):
        if start_vertex not in self.graph:
            print("起始顶点不存在")
            return
        #已访问顶点
        visited = set()

        self._dfs_recursive(start_vertex, visited)
        print()

    def _dfs_recursive(self, vertex, visited):
        visited.add(vertex)
        print(vertex, end = " ")
