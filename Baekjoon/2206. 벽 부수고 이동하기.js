const { pbkdf2 } = require('crypto');

const getReadLine = () => {
    const readline = require('readline');
    return readline.createInterface({
        input: process.stdin,
        output: process.stdout
    })
}
const rl = getReadLine();

class queue{
    constructor(){
        this.q=[]
    }
    push(item){
        this.q.push(item)
    }
    pop(){
        return this.q.shift()
    }
}

const solve = input => {
    let N=input[0][0]*1, M=input[0][1]*1;
    let arr=[], visit=[]
    let qx=new queue, qy=new queue, qb=new queue
    let dx=[0, 0, -1, 1], dy=[1, -1, 0, 0]

    for(let i=1; i<N+1; i++)
    {
        let temp=[]
        for(let j=0; j<M; j++)
            temp.push(input[i][0][j]*1)
        arr.push(temp)
    }

    for(let i=0; i<2; i++)
    {
        temp2=[]
        for(let j=0; j<N; j++)
        {
            let temp=[]
            for(let k=0; k<M; k++)
                temp.push(0)
            temp2.push(temp)
        }
        visit.push(temp2)
    }

    arr[0][0]=1
    visit[0][0][0]=1
    qx.push(0); qy.push(0); qb.push(0)

    if(N==1 && M==1)
    {
        console.log(1)
        return
    }

    qx.push(0); qy.push(0); qb.push(0)
    while(qx.q.length!=0)
    {
        let x=qx.pop(); let y=qy.pop(); let b=qb.pop();
        if(x==N-1 && y==M-1)
        {
            console.log(visit[b][x][y])
            return
        }

        for(let i=0; i<4; i++)
        {
            if(x+dx[i]>=0 && x+dx[i]<N && y+dy[i]>=0 && y+dy[i]<M)
            {
                if(arr[x+dx[i]][y+dy[i]]==0 && visit[0][x+dx[i]][y+dy[i]]==0 && b==0)
                {
                    visit[0][x+dx[i]][y+dy[i]]=visit[0][x][y]+1
                    qx.push(x+dx[i]); qy.push(y+dy[i]); qb.push(b)
                }
                else if(arr[x+dx[i]][y+dy[i]]==1 && visit[0][x+dx[i]][y+dy[i]]==0 && b==0)
                {
                    visit[1][x+dx[i]][y+dy[i]]=visit[0][x][y]+1 
                    qx.push(x+dx[i]); qy.push(y+dy[i]); qb.push(1)
                }
                else if(arr[x+dx[i]][y+dy[i]]==0 && visit[1][x+dx[i]][y+dy[i]]==0 && b==1)
                {
                    visit[1][x+dx[i]][y+dy[i]]=visit[1][x][y]+1 
                    qx.push(x+dx[i]); qy.push(y+dy[i]); qb.push(1)
                }
            }
        }
    }
    console.log(-1)
}

const input = [];
const start = (rl) => {
    rl.on('line', line => {
        input.push(line.split(' '));
    }).on('close', () => {
        solve(input);
        process.exit();
    })
}
start(rl);