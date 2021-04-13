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
    let t=input[0][0]*1
    let price=[]

    for(let i=1; i<t+1; i++)
        price.push(input[i][0]*1)

    for(let i=0; i<price.length; i++)
    {
        let count=0

        for(; price[i]!=0;)
        {
            let q=new queue
            let price_r=price[i]%100
            price[i]=Math.floor(price[i]/100)
            q.push([price_r, 0])
            while(q.size!=0)
            {
                let temp=q.pop()
                let x=temp[0];
                let c=temp[1];

                if(x==0)
                {
                    count+=c
                    break
                }
                if(x-25>=0)
                    q.push([x-25, c+1])
                if(x-10>=0)
                    q.push([x-10, c+1])
                if(x-1>=0)
                    q.push([x-1, c+1])
            }
        }
        console.log(count)
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