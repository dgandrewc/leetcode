const getReadLine = () => {
    const readline = require('readline');
    return readline.createInterface({
        input: process.stdin,
        output: process.stdout
    })
}
const rl = getReadLine();

class node{
    constructor(item){
        this.next=null
        this.item=item
    }
}

class queue
{
    constructor(){
        this.head=null
        this.tail=null
        this.size=0
    }

    push(item){
        let nodeT=new node(item)
        if(this.head==null)
            this.head=nodeT
        else
            this.tail.next=nodeT
        this.tail=nodeT
        this.size+=1
    }

    pop(){
        let item=this.head.item
        this.head=this.head.next
        this.size-=1;
        return item
    }
}

const solve = input => {
    let N=input[0][0]*1, M=input[0][1]*1, K=input[0][2]*1
    let arr=[], visit=[]
    let q=new queue
    let dx=[0, 0, -1, 1], dy=[1, -1, 0, 0]

    for(let i=1; i<N+1; i++)
    {
        let temp=[]
        for(let j=0; j<M; j++)
            temp.push(input[i][0][j]*1)
        arr.push(temp)
    }

    for(let i=0; i<K+1; i++)
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
    visit[0][0][0]=1

    if(N==1 && M==1)
    {
        console.log(1)
        return
    }

    q.push([0, 0, 0])
    while(q.size!=0)
    {
        let temp=q.pop()
        let x=temp[0], y=temp[1], b=temp[2];
        if(x==N-1 && y==M-1)
        {
            console.log(visit[b][x][y])
            return
        }

        for(let i=0; i<4; i++)
            if(x+dx[i]>=0 && x+dx[i]<N && y+dy[i]>=0 && y+dy[i]<M)
                if(arr[x+dx[i]][y+dy[i]]==0 && visit[b][x+dx[i]][y+dy[i]]==0 && b<=K)
                {
                    visit[b][x+dx[i]][y+dy[i]]=visit[b][x][y]+1
                    q.push([x+dx[i], y+dy[i], b])
                }
                else if(arr[x+dx[i]][y+dy[i]]==1 && visit[b][x+dx[i]][y+dy[i]]==0 && b<K)
                {
                    visit[b+1][x+dx[i]][y+dy[i]]=visit[b][x][y]+1 
                    q.push([x+dx[i], y+dy[i], b+1])
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