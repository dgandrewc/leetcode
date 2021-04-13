/* priority_queue*/
class priority_queue
{
    constructor(){
        this.q=[0]
        this.size=0
    }

    push(item){
        this.size++
        let i=this.size

        while(this.q[Math.floor(i/2)]>=item && i!=1)
        {
            this.q[i]=this.q[Math.floor(i/2)]
            i=Math.floor(i/2)
        }
        this.q[i]=item
    }
    
    pop(){
        let remove=this.q[1]
        let temp=this.q.pop()
        this.q[1]=temp
        this.size--

        let parent=1
        let child=2
        while(child<=this.size)
        {
            if(this.q[child]>this.q[child+1] && child<=this.size)
                child+=1

            if(temp<this.q[child])
                break

            this.q[parent]=this.q[child]
            parent=child
            child*=2
        }
        this.q[parent]=temp
        return remove
    }
}
/* priority_queue*/

/* queue */
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
/* queue */

const getReadLine = () => {
    const readline = require('readline');
    return readline.createInterface({
        input: process.stdin,
        output: process.stdout
    })
}
const rl = getReadLine();

const solve = input => {

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