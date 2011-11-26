d<-read.csv("result.txt",sep=" ")
d.label<-d[,1]
plot(d[,2],d[,3])
plot(d[,2],d[,3],type="n")
text(d[,2],d[,3],d.label)

