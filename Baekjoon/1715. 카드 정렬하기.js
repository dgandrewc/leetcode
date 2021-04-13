const getReadLine = () => {
    const readline = require('readline');
    return readline.createInterface({
        input: process.stdin,
        output: process.stdout
    })
}
const rl = getReadLine();
class priority_queue
{
    constructor(){
        this.q=[0]
        this.size=0
    }

    enqueue(item){
        this.size++

        let i=this.size
        while(this.q[Math.floor(i/2)]>=item && i!=1)
        {
            this.q[i]=this.q[Math.floor(i/2)]
            i=Math.floor(i/2)
        }
        this.q[i]=item
    }
    dequeue(){
        let remove=this.q[1]
        let temp=this.q.pop()
        this.q[1]=temp
        this.size--

        let parent=1
        let child=2

        while(child<=this.size)
        {
            if(this.q[child]>this.q[child+1] && child<this.size)
                child+=1
            if(temp<=this.q[child]) break;
            this.q[parent]=this.q[child]
            parent=child
            child*=2
        }
        this.q[parent]=temp
        return remove
    }
}
const solve = input => {
    let q=new priority_queue
    let n=input[0][0]*1
    let arr=[]
    let ans=0

    for(let i=1; i<n+1; i++)
        q.enqueue(input[i][0]*1)

    while(q.size>1)
    {
        let a=q.dequeue()
        let b=q.dequeue()
        ans=ans+a+b
        q.enqueue(a+b)
    }
    console.log(ans)
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