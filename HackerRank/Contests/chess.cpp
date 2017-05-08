#include <iostream>
#include <cstdio>
#include <string>
#include <sstream> 
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <cassert>
#include <cctype>
#include <tuple>
#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define mp make_pair
#define pii pair<int,int>
#define vi vector<int>
#define SZ(x) ((int)(x.size()))
#define fi first
#define se second
#define FOR(i,n) for(int (i)=0;(i)<(n);++(i))
#define FORI(i,n) for(int (i)=1;(i)<=(n);++(i))
#define IN(x,y) ((y).find((x))!=(y).end())
#define ALL(t) t.begin(),t.end()
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define REP(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define REPD(i,a,b) for(int (i)=(a); (i)>=(b);--i)
#define REMAX(a,b) (a)=max((a),(b));
#define REMIN(a,b) (a)=min((a),(b));
#define DBG cout << "debug here" << endl;
#define DBGV(vari) cout << #vari<< " = "<< (vari) <<endl;

typedef long long ll;

const int T = 2001;
const int W = 7;
const int M = 6;

const int ROWS = 4;
const int COLS = 4;

string COL_NAMES = "ABCDEFGH";
string COLOR_NAMES = "WB";

#define EMPTY 0
#define QUEEN 1
#define ROOK 2
#define BISHOP 3
#define KNIGHT 4
#define PAWN 5

#define WHITE 0
#define BLACK 1

int codeFigure(char color, char type)
{
    int code;
    if(type == 'Q') code = QUEEN;
    else if(type == 'R') code = ROOK;
    else if(type == 'B') code = BISHOP;
    else if(type == 'N') code = KNIGHT;
    else if(type == 'P') code = PAWN;
    //else assert(false);

    if(color == 'W') code *= 2;
    else if(color == 'B') code = 2 * code + 1;
    //else assert(false);

    return code;
}

char figureToChar(int figure)
{
    if(figure == EMPTY) return '*';
    int color = figure % 2;
    int type = figure / 2;
    if(type == QUEEN) return (color == WHITE) ? 'Q' : 'q';
    else if(type == ROOK) return (color == WHITE) ? 'R' : 'r';
    else if(type == BISHOP) return (color == WHITE) ? 'B' : 'b';
    else if(type == KNIGHT) return (color == WHITE) ? 'N' : 'n';
    else if(type == PAWN) return (color == WHITE) ? 'P' : 'p';
    else assert(false);
}

int getColor(int figure) 
{ 
    //assert(figure != EMPTY);
    return figure % 2; 
}

int getType(int figure) 
{ 
    return figure / 2; 
}

int oppositeColor(int color) 
{ 
    return 1 - color; 
}

//typedef int Board[ROWS][COLS];
typedef vector<vi> Board;

void printBoard(Board board)
{
    cout << "    A B C D E F G H" << endl;
    REPD(i, ROWS - 1, 0)
    {
        cout << i << " | ";
        REP(j, 0, COLS - 1)
        {
            cout << figureToChar(board[i][j]) << " ";
        }
        cout << endl;
    }
}

bool onBoard(tuple<int, int, int> pos)
{
    return get<0>(pos) >= 0 && get<0>(pos) < ROWS && get<1>(pos) >= 0 && get<1>(pos) < COLS;
}

vector<tuple<int, int, int> > getStraightMoves(pii pos, Board& board, int type)
{
    vector<tuple<int, int, int> > res;
    //vertical moves up
    REP(i, pos.fi + 1, ROWS - 1) 
    {
        auto p = make_tuple(i, pos.se, type);
        res.pb(p);
        if(board[get<0>(p)][get<1>(p)] != EMPTY) break;
    }
    //vertical moves down
    REPD(i, pos.fi -1, 0)
    {
        auto p = make_tuple(i, pos.se, type);
        res.pb(p);
        if(board[get<0>(p)][get<1>(p)] != EMPTY) break;
    }
    //horizontal moves right
    REP(j, pos.se + 1, COLS - 1)
    {
        auto p = make_tuple(pos.fi, j, type);
        res.pb(p);
        if(board[get<0>(p)][get<1>(p)] != EMPTY) break;
    }
    //horizontal moves right
    REPD(j, pos.se - 1, 0)
    {
        auto p = make_tuple(pos.fi, j, type);
        res.pb(p);
        if(board[get<0>(p)][get<1>(p)] != EMPTY ) break;
    }
    return res;
}



vector<tuple<int, int, int> > getDiagonalMoves(pii pos, Board& board, int type)
{
    vector<tuple<int, int, int> > res;
    //up-right diagonal
    int r = pos.fi + 1;
    int c = pos.se + 1;
    while(r < ROWS && c < COLS)
    {
        auto p = make_tuple(r, c, type);
        res.pb(p);
        if(board[get<0>(p)][get<1>(p)] != EMPTY ) break;
        ++r;
        ++c;
    }
    //bottom-left diagonal
    r = pos.fi - 1;
    c = pos.se - 1;
    while(r >= 0 && c >= 0)
    {
        auto p = make_tuple(r, c, type);
        res.pb(p);
        if(board[get<0>(p)][get<1>(p)] != EMPTY) break;
        --r;
        --c;
    }
    //up-left diagonal
    r = pos.fi + 1;
    c = pos.se - 1;
    while(r < ROWS && c >= 0)
    {
        auto p = make_tuple(r, c, type);
        res.pb(p);
        if(board[get<0>(p)][get<1>(p)] != EMPTY) break;
        ++r;
        --c;
    }
    //bottom-right diagonal
    r = pos.fi - 1;
    c = pos.se + 1;
    while(r >= 0 && c < COLS)
    {
        auto p = make_tuple(r, c, type);
        res.pb(p);
        if(board[get<0>(p)][get<1>(p)] != EMPTY) break;
        --r;
        ++c;
    }
    return res;
}

vector<tuple<int, int, int> > getKnightMoves(pii pos)
{
    vector<tuple<int, int, int> > res;
    int r, c;

    int rs[] = {1,2,2,1,-1,-2,-2,-1};
    int cs[] = {-2,-1,1,2,2,1,-1,-2};
    FOR(i, 8)
    {
        r = pos.fi + rs[i];
        c = pos.se + cs[i];
        auto p = make_tuple(r, c, KNIGHT);
        if(onBoard(p)) res.pb(p);
    }
    return res;
}

vector<tuple<int, int, int> > getPawnMoves(pii pos, Board& board, int colorToMove)
{
    vector<tuple<int, int, int> > res;

    if(colorToMove == 0)
    {
        // vertical up move
        auto q = make_tuple(pos.fi + 1, pos.se, 5);
        if(onBoard(q) && board[pos.fi + 1][pos.se] == EMPTY)
        {
            if(pos.fi + 1 == 3)
            {
                get<2>(q) = KNIGHT;
                res.pb(q);
                get<2>(q) = ROOK;
                res.pb(q);
                get<2>(q) = BISHOP;
                res.pb(q);
            }
            else
                res.pb(q);

        }
        
        // upper right diagonal move
        auto p = make_tuple(pos.fi + 1, pos.se+1, 5);
        if( onBoard(p) && board[pos.fi + 1][pos.se+1] != EMPTY && getColor(board[pos.fi+1][pos.se+1]) == oppositeColor(colorToMove))
        {
            if(pos.fi + 1 == 3)
            {
                get<2>(p) = KNIGHT;
                res.pb(p);
                get<2>(p) = ROOK;
                res.pb(p);
                get<2>(p) = BISHOP;
                res.pb(p);
            }
            else
                res.pb(p);
        }

        // upper left diagonal move
        auto r = make_tuple(pos.fi + 1, pos.se-1, 5);
        if( onBoard(r) && board[pos.fi + 1][pos.se-1] != EMPTY  && getColor(board[pos.fi+1][pos.se-1]) == oppositeColor(colorToMove))
        {
            if(pos.fi + 1 == 3)
            {
                get<2>(r) = KNIGHT;
                res.pb(r);
                get<2>(r) = ROOK;
                res.pb(r);
                get<2>(r) = BISHOP;
                res.pb(r);
            }
            else
                res.pb(r);
        }
    }
    else
    {
        // vertical down move
        auto s = make_tuple(pos.fi - 1, pos.se, 5);
        if(onBoard(s) && board[pos.fi - 1][pos.se] == EMPTY)
        {    
            if(pos.fi - 1 == 0)
            {
                get<2>(s) = KNIGHT;
                res.pb(s);
                get<2>(s) = ROOK;
                res.pb(s);
                get<2>(s) = BISHOP;
                res.pb(s);                
            }
            else
                res.pb(s);
        }
        
        // lower right diagonal move
        auto w = make_tuple(pos.fi - 1, pos.se + 1, 5);
        if(onBoard(w) && board[pos.fi - 1][pos.se + 1] != EMPTY  && getColor(board[pos.fi-1][pos.se+1]) == oppositeColor(colorToMove))
        {
            if(pos.fi - 1 == 0)
            {
                get<2>(w) = KNIGHT;
                res.pb(w);
                get<2>(w) = ROOK;
                res.pb(w);
                get<2>(w) = BISHOP;
                res.pb(w);               
            }
            else
                res.pb(w);
        }

        // lower left diagonal move
        auto e = make_tuple(pos.fi - 1, pos.se - 1, 5);
        if(onBoard(e) && board[pos.fi - 1][pos.se - 1] != EMPTY && getColor(board[pos.fi-1][pos.se-1]) == oppositeColor(colorToMove))
        {
            if(pos.fi - 1 == 0)
            {
                get<2>(e) = KNIGHT;
                res.pb(e);
                get<2>(e) = ROOK;
                res.pb(e);
                get<2>(e) = BISHOP;
                res.pb(e);   
            }
            else
                res.pb(e);
        }
    }
    return res;
}
vector<tuple<int, int, int> > getMoves(int figureType, pii pos, Board& board, int colorToMove)
{
    vector<tuple<int, int, int> > res;
    vector<tuple<int, int, int> > tmp;

    switch(figureType)
    {
    case QUEEN:
        res = getStraightMoves(pos, board, QUEEN);
        tmp = getDiagonalMoves(pos, board, QUEEN);
        res.insert(res.end(), tmp.begin(), tmp.end());
        break;
    case BISHOP:
        res = getDiagonalMoves(pos, board, BISHOP);
        break;
    case ROOK:
        res = getStraightMoves(pos, board, ROOK);
        break;
    case KNIGHT:
        res = getKnightMoves(pos);
        break;
    case PAWN:
        res =  getPawnMoves(pos, board, colorToMove);
        break;
    default:
        cout << "! " << figureType << endl;
        assert(false);
    }
    return res;
}

int initialMoves;
int scenario = 1;
int solve(int colorToMove, Board board, int remainingMoves)
{
    if(remainingMoves == 0) return BLACK;
    vector<pii> positions;
    FOR(i, ROWS) FOR(j, COLS) if(board[i][j] != EMPTY && getColor(board[i][j]) == colorToMove) positions.pb(mp(i, j));
    FOR(k, positions.size())
    {
        auto pos = positions[k];
        auto moves = getMoves(getType(board[pos.fi][pos.se]), pos, board, colorToMove);
        FOR(j, moves.size())
        {
            auto p = moves[j];
            if(board[get<0>(p)][get<1>(p)] != EMPTY && getColor(board[get<0>(p)][get<1>(p)]) == colorToMove) 
                continue;
            //capturing QUEEN?
            if(board[get<0>(p)][get<1>(p)] != EMPTY && getColor(board[get<0>(p)][get<1>(p)]) == oppositeColor(colorToMove) && getType(board[get<0>(p)][get<1>(p)]) == QUEEN) 
            {
                return colorToMove;
            }
            //move to empty field or capturing a regular piece
            if(board[get<0>(p)][get<1>(p)] == EMPTY || getColor(board[get<0>(p)][get<1>(p)]) == oppositeColor(colorToMove))
            {
                auto newBoard = board;
                newBoard[pos.fi][pos.se] = EMPTY;
                newBoard[get<0>(p)][get<1>(p)] = board[pos.fi][pos.se];
                auto tmp = solve(oppositeColor(colorToMove), newBoard, remainingMoves - 1);
                if(tmp == colorToMove) return colorToMove;
            }
        }
    }
    return oppositeColor(colorToMove);
}

int main()    
{
    ios_base::sync_with_stdio(0);
    int tests;
    cin >> tests;
    assert(tests >= 1 && tests <= T);
    while(tests--)
    {
        int w, b, m;
        cin >> w >> b >> m;
        assert(w >= 1 && w <= W);
        assert(b >= 1 && b <= W);
        assert(m >= 1 && m <= M);

        initialMoves = m;
        scenario = 1;

        Board board = vector<vi> (ROWS, vi(COLS, EMPTY));
        set<pii> positions;
        FOR(i, w + b)
        {
            char type;
            char column;
            int row;
            cin >> type >> column >> row;
            char color = (i < w) ? 'W' : 'B';
            int figure = codeFigure(color, type);
            int found = 0;
            FOR(j, COLS) if(column == COL_NAMES[j]) found = 1;
            //assert(found);
            //assert(row >= 1 && row <= ROWS);

            auto pos = mp(row - 1, (int)(column - 'A'));
            board[pos.fi][pos.se] = figure;
            positions.insert(pos);
        }
        //assert(positions.size() == w + b);
        int res = solve(WHITE, board, m);
        if(res == WHITE) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}