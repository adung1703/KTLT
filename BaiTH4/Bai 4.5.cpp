void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bat dau tu dinh so 1
    //# Nguyen Huu Dung - 20215545 #
    
    int currentV;

    while (!S.empty()) {
        currentV = S.top();
        S.pop(); //Luu dinh hien tai trong stack
        if (!visited[currentV]) { //Chi xet nhung dinh chua tham
        	visited[currentV] = true; //Danh dau da tham
        	cout << currentV << endl; //In ra dinh hien tai      
        	//De duyet tu trai qua phai thi ta phai push theo chieu nguoc lai
        	stack<int> S1; 
        	
	        for (int i : adj[currentV]) {
	            if (!visited[i]) S1.push(i); 
	        } //Ta dung tam mot stack S1 de dua tung dinh con cua dinh currentV
	        
	        while (!S1.empty()) {
	        	S.push(S1.top());
	        	S1.pop();
			} //Push nguoc lai vao S
		}
    }
} //Nguyen Huu Dung - 20215545
