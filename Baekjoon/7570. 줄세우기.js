const getReadLine = () => {
    const readline = require('readline');
    return readline.createInterface({
        input: process.stdin,
        output: process.stdout
    })
}
const rl = getReadLine();

const solve = input => {
    let n=input[0][0]*1
    let arr=[]
    let dp=[]

    dp.push(0)
    arr.push(0)
    for(let i=0; i<n; i++)
    {
        arr.push(input[1][i])
        dp.push(0)
    }

    let max=0
    for(let i=1; i<n+1; i++)
    {
        v=arr[i]
        dp[v]=dp[v-1]+1
        if(max<dp[v])
            max=dp[v]
    }
    console.log(n-max)
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