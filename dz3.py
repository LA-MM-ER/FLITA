import networkx as nwx
import matplotlib.pyplot as mpt

with open('list_of_edges177.txt', 'r') as file:
    edges = [line.strip().split() for line in file]
    print(edges)

G = nwx.Graph()
for edge in edges:
    if len(edge) == 1:
        G.add_node(edge[0])
    elif len(edge) == 2:
        G.add_edge(edge[0], edge[1])
    else:
        print('Invalid input of edges')
        break

nwx.draw(G, with_labels=True)
mpt.show()
print("By the graph connectivity theorem:")
if len(G.edges) > ((len(G.nodes) - 1) * (len(G.nodes) - 2) * 0.5):
    print("Graph is connected")
else:
    print("Graph is not connected")
