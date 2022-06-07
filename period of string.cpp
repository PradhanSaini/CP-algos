void build_prefix(int pi[],string &S)
{
    int lgprefix = 0;
    int N=S.size()-1;

    pi[1] = 0;

    for ( int i = 2; i <= N; ++i )
    {
        while ( lgprefix > 0 && S[i] != S[ lgprefix + 1 ] )
                    lgprefix = pi[ lgprefix ];

        if ( S[i] == S[ lgprefix + 1 ] )
                lgprefix++;

        pi[i] = lgprefix;
    }
}

void KMP(string &SS,string &S,int d[],int pi[])
{
    int lgprefix = 0;
    int N=S.size()-1;

    for ( int i = 1; i <= 2 * N; ++i )
    {
        while ( lgprefix > 0 && SS[i] != S[ lgprefix + 1 ] )
                lgprefix = pi[lgprefix];

        if ( SS[i] == S[ lgprefix + 1 ] )
                lgprefix++;

        d[i] = lgprefix;
    }
}

int period(string &t){
    int n=t.size()-1;
    string tt=t+t.substr(1,n);
    int pi[2*n+1]={0};
    int d[2*n+1]={0};
    build_prefix(pi,t);
    KMP(tt,t,d,pi);
    int count = 0;
    int N=t.size()-1;
    for ( int i = 1; i <= 2 * N; ++i )
    {
        if ( d[i] == N )
                count++;

        if ( count == 2 )
        {
            return i - N ;
            break;
        }
    }

    return 0;
}
