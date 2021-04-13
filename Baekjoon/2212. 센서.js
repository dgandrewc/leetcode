const readline=require("readline");
const rl=readline.createInterface({
	input: process.stdin,
	output: process.stdout
});

Array.prototype.pushIfNotExist=function(element){
	for(var i=0; i<this.length; i++)
	{
		if(element[0]==this[i][0] && element[1]==this[i][1])
			return false;
	}
	return true;
}

var N;
var K;
var arr=[];
var dist=[];

rl.on("line", (input)=>{
	arr.push(input.split(' '));
}).on('close', ()=>{
	N=arr[0][0]*1;
	K=arr[1][0]*1;
	arr=arr[2]
	 if (K >= N){
        console.log("0");
        return 0;
    }
	for(i in arr)
		arr[i]*=1;

	arr.sort(function(a, b){
		return a-b;
	})

	for(var i=0; i<K-1; i++)
	{
		var max=0;
		var max_temp;
		for(var j=0; j<arr.length-1; j++)
		{
			if(arr[j+1]-arr[j]>max && dist.pushIfNotExist([arr[j], arr[j+1]]))
			{
				max=arr[j+1]-arr[j];
				max_temp=[arr[j], arr[j+1]];
			}
		}
		dist.push(max_temp);
	}
	dist.sort();
	var start=arr[0];
	var result=0;
	for(i of dist)
	{
		result+=(i[0]-start);
		start=i[1];
	}
	result+=(arr[arr.length-1]-start)
	console.log(result);
})