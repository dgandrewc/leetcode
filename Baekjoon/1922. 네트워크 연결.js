const getReadLine = () => {
    const readline = require('readline');
    return readline.createInterface({
        input: process.stdin,
        output: process.stdout
    })
}
const rl = getReadLine();

parent=[0]

function find(x)
{
    if(x==parent[x])
        return x
    else
    {
        let y=find(parent[x])
        parent[x]=y
        return y
    }
}

function union(x, y)
{
    x=find(x)
    y=find(y)
    if(x!=y)
        parent[y]=x
}

const solve = input => {
    let n=input[0][0]*1
    let m=input[1][0]*1
    let arr=[]
    let cost=0

    for(let i=2; i<m+2; i++)
        arr.push([input[i][0]*1, input[i][1]*1, input[i][2]*1])
    arr=arr.sort((a, b)=>a[2]-b[2])

    for(let i=1; i<n+1; i++)
        parent.push(i)

    for(let i=0; i<m; i++)
    {
        if(find(arr[i][0])!=find(arr[i][1]))
        {
            union(arr[i][0], arr[i][1])
            cost+=arr[i][2]
        }
    }
    console.log(cost)
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