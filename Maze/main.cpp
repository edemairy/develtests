#include <QtCore/QCoreApplication>

#include <map>
#include <bitset>
#include <vector>
#include <list>
#include <cstdlib>
#include <QTextStream>
using namespace std;
typedef map<int,vector<bool> > Maze;

typedef map< int, vector<int> > CfcMap;
CfcMap cfcMap;
typedef map<int, int> SizeCfcMap;
SizeCfcMap sizeCfcMap;

void genMaze( Maze& maze, int m, int n, float p ) {
   maze.clear();
   maze[0] = vector<bool>( n+2, false );
   maze[m+1] = vector<bool>( n+2, false );
   for ( int i = 1; i <= m; ++i ) {
       maze[i] = vector<bool>( n+2, false );
       for ( int j = 1; j <= n; ++j ) {
           float pr = (1.0*rand()) / RAND_MAX;
           maze[i][j] = ( pr > p );
       }
   }
}

void displayMaze( Maze& maze ) {
    int m = maze.size();
    int n = maze[0].size();
    QTextStream out(stdout);
    for ( int i = 0; i < m; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            out << ( (maze[i][j] ) ? "." : "#" );
        }
        out << "\n";
    }
    out.flush();
}
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

void cfcMaze( Maze& maze ) {
    Maze visited = maze;
    int m = maze.size();
    int n = maze[0].size();
    for (int i = 0; i < m; ++i ){
        cfcMap[i].resize(n+2);
    }
    QTextStream out(stdout);
    int cfcNum = 1;
    for ( int i = 0; i < m; ++i ) {
        for ( int j = 0; j < n; ++j ) {

            if ( maze[i][j] && visited[i][j] ) {
                int sizeCfc = 0;
                list<pair<int, int> > lp;
                lp.push_back( make_pair(i,j) );
                while ( !lp.empty()) {
                    pair<int, int> current = lp.back();
                    lp.pop_back();
                    visited[ current.first ][current.second ] = false;
                    cfcMap[ current.first ][current.second ] = cfcNum;
                    sizeCfc++;
                    for (int dir=0; dir<4; dir++) {
                        pair<int, int> nc = make_pair( current.first + dx[dir], current.second + dy[dir]);
                        if ( visited[nc.first][nc.second]) {
                            lp.push_back( nc );
                        }
                    }
                }
                sizeCfcMap[cfcNum] = sizeCfc;
                cfcNum++;
            }
        }
    }
    for ( int i = 0; i < m; ++i ) {
        for ( int j = 0; j < n; ++j ) {
            out << cfcMap[i][j] << " ";
        }
        out << "\n";
    }
    for ( SizeCfcMap::iterator it = sizeCfcMap.begin(); it != sizeCfcMap.end(); ++it ) {
        out << "cfc #" << it->first << " = " << it->second << "\n";
    }

    out.flush();

}


int main(int argc, char *argv[])
{
    Maze maze;
    genMaze(maze, 10,10, .3);
    displayMaze(maze);
    cfcMaze(maze);
   // QCoreApplication a(argc, argv);

   // return a.exec();
}
