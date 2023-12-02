Thuật toán BFS (Breadth-First Search) không đảm bảo cho kết quả là một thứ tự tô pô (topological sort) vì nó không xem xét đến hướng của các cạnh trong đồ thị.
Thứ tự tô pô của một đồ thị hướng là một cách sắp xếp các đỉnh sao cho mọi cạnh (u, v) đều dẫn từ một đỉnh u đến một đỉnh v có thứ tự sau u.
Điều này có nghĩa là nếu có một cạnh (u, v), thì u phải xuất hiện trước v trong thứ tự.
Trong khi đó, BFS khám phá đồ thị theo chiều rộng, bắt đầu từ một đỉnh nguồn và di chuyển đến tất cả các đỉnh kề với nó, sau đó đến các đỉnh kề với các đỉnh đã khám phá, và cứ tiếp tục như vậy.
BFS không quan tâm đến hướng của các cạnh, nên không thể đảm bảo rằng một đỉnh sẽ xuất hiện trước tất cả các đỉnh mà nó dẫn đến trong thứ tự tô pô.
Vì vậy, để tạo ra một thứ tự tô pô cho một đồ thị hướng không chu trình, ta thường sử dụng thuật toán DFS (Depth-First Search) hoặc thuật toán Kahn, chứ không phải BFS.
