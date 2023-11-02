void bfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> visited(adj.size());
    Q.push(1); // Bat dau tu dinh so 1
    //# Nguyen Huu Dung - 20215545 #
    
    int currentV; // Luu dinh hien tai duyet toi

    while (!Q.empty()) { //Khi Queue van con phan tu
        currentV = Q.front(); //Duyet tung phan tu trong queue
        Q.pop();  //Xoa phan tu trong queue
        
        if (!visited[currentV]) { //Neu dinh hien tai chua tham toi 
			cout << currentV << endl;  //In ra 
			visited[currentV] = true; //Danh dau da duyet
		}
        
        for (int i : adj[currentV]) { //Duyet tung dinh con cua dinh hien tai
            if (!visited[i]) Q.push(i); //Cho vao queue
        }   
    } //Do queue co che FILO nen se in ra cac dinh cha truoc
} //Nguyen Huu Dung - 20215545
