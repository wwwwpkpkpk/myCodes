//Language used: C++

int x, y, n, dist = 0;

cout << "Enter the first number: ";
cin >> u;

cout << "Enter the second number:";
cin >> y;

n = x^y;

while(n) {
  dist++;
  n &= n - 1;
}

cout << dist << endl;
