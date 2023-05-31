import graphviz

with open("list_of_edges177.txt", 'r') as file:
    graph = graphviz.Graph()
    edges = []
    for line in file:
        vertexes = line.split()
        if len(vertexes) == 2:
            graph.edge(vertexes[0], vertexes[1])
            edges.append(vertexes)
        elif len(vertexes) == 1:  # одинокая вершина
            graph.node(vertexes[0])
            edges.append(vertexes)
        else:
            print("Invalid input")
            break
    print(edges)
graph.view()
