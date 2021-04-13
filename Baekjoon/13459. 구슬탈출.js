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
    let n=input[0][0]*1
    let m=input[0][1]*1
    let map=[]
    let qr=new queue, qb=new queue, qc=new queue, ql=new queue
    let dx=[0, 1, 0, -1], dy=[1, 0, -1, 0]

    for(let i=1; i<n+1; i++)
    {
        temp=[]
        for(let j=0; j<m; j++)
        {
            if(input[i][0][j]=='R')
                qr.push([i-1, j])
            if(input[i][0][j]=='B')
                qb.push([i-1, j])
            temp.push(input[i][0][j])
        }
        map.push(temp)
    }
    qc.push(1)
    ql.push(undefined)

    while(qr.size!=0)
    {
        let r=qr.pop(), b=qb.pop(), c=qc.pop(), l=ql.pop()
        let rx=r[0], ry=r[1], bx=b[0], by=b[1]
        if(c==11)
            continue

        for(let i=0; i<4; i++)
        {
            if(map[rx+dx[i]][ry+dy[i]]=='#' && map[bx+dx[i]][by+dy[i]]=='#')
                continue //둘다 이동불가시 스킵
            let flag1=0, flag2=0, flag3=0, j, k
            if(dx[i]==0 && (l+2)%4!=i) //y간 이동의 경우 && 이전 이동경로 방지
            {
                for(k=by+dy[i]; map[bx][k]!='#'; k+=dy[i]) //벽에 부딪힐때까지 파란공 이동
                {
                    if(map[bx][k]=='O') { flag3=1} //파란공이 먼저 빠지면 스킵
                    if(rx==bx && ry==k) flag2=1 //가다가 빨간공이 있으면 한칸뺌
                }
                for(j=ry+dy[i]; map[rx][j]!='#'; j+=dy[i]) //벽에 부딪힐때까지 빨간공 이동
                {
                    if(map[rx][j]=='O' && flag3!=1) {console.log(1); return} //빨간공이 빠지면 끝
                    if(rx==bx && j==by) flag1=1; // 가다가 파란공이 있으면 한칸뺌
                }
                k-=dy[i]; j-=dy[i];
                if(flag1==1) j-=dy[i]
                if(flag2==1) k-=dy[i]
                if(flag3==0)
                {
                    qr.push([rx, j]); qb.push([bx, k]); qc.push(c+1); ql.push(i)
                }
            }
            else if(dy[i]==0 && (l+2)%4!=i) //x간 이동의 경우 && 이전 이동경로 방지
            {
                for(k=bx+dx[i]; map[k][by]!='#'; k+=dx[i]) //벽에 부딪힐때까지 파란공 이동
                {
                    if(map[k][by]=='O') {flag3=1}; //파란공이 먼저 빠지면 스킵
                    if(k==rx && ry==by) flag2=1; //가다가 빨간공이 있으면 한칸 뺌
                }
                for(j=rx+dx[i]; map[j][ry]!='#'; j+=dx[i]) //벽에 부딪힐 때까지 빨간공 이동
                {
                    if(map[j][ry]=='O' && flag3!=1) {console.log(1); return} //빨간공이 빠지면 끝
                    if(j==bx && ry==by) flag1=1; //가다가 파란공이 있으면 한칸뺌
                }
                k-=dx[i]; j-=dx[i];
                if(flag1==1) j-=dx[i]
                if(flag2==1) k-=dx[i]
                if(flag3==0)
                {
                    qr.push([j, ry]); qb.push([k, by]); qc.push(c+1); ql.push(i)
                }
            }
        }
    }
    console.log(0)
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