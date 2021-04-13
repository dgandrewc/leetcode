const { strictEqual } = require('assert');
const { SSL_OP_NO_TLSv1_1 } = require('constants');

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

let store=[]
let visit=[]

const solve = input => {
    for(let i=0; i<10000; i++)
        store.push(true)

    for(let i=2; i<store.length; i++)
        if(store[i])
            for(let j=2; i*j<store.length; j++)
                store[i*j]=false

    for(let i=0; i<1000; i++)
        store[i]=false

    let t=input[0][0]*1

    for(let i=1; i<t+1; i++)
    {
        let visit=[]
        for(let i=0; i<10000; i++)
            visit.push(false)

        let a=input[i][0]
        let q=new queue
        let flag=0

        q.push([a[0], a[1], a[2], a[3], 0])
        while(q.size!=0)
        {
            temp=q.pop()
            let n1=temp[0], n2=temp[1], n3=temp[2], n4=temp[3], c=temp[4]

            if(Number(n1+n2+n3+n4)==input[i][1]*1)
            {
                console.log(c)
                flag=1
                break
            }

            let j=0
            for(j=0; j<=9; j++)
            {
                if(j!=0 && store[Number(j+n2+n3+n4)] && !visit[Number(j+n2+n3+n4)])
                {
                    q.push([String(j), String(n2), String(n3), String(n4), c+1])
                    visit[Number(j+n2+n3+n4)]=true
                }
                if(store[Number(n1+j+n3+n4)] && !visit[Number(n1+j+n3+n4)])
                {
                    q.push([String(n1), String(j), String(n3), String(n4), c+1])
                    visit[Number(n1+j+n3+n4)]=true
                }
                if(store[Number(n1+n2+j+n4)] && !visit[Number(n1+n2+j+n4)])
                {
                    q.push([String(n1), String(n2), String(j), String(n4), c+1])
                    visit[Number(n1+n2+j+n4)]=true
                }
                if(store[Number(n1+n2+n3+j)] && !visit[Number(n1+n2+n3+j)])
                {
                    q.push([String(n1), String(n2), String(n3), String(j), c+1])
                    visit[Number(n1+n2+n3+j)]=true
                }
            }
        }
        if(flag==0)
            console.log('Impossible')
    }
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