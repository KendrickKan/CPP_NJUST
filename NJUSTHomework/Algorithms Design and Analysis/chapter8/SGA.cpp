# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <math.h>
/****** the definition of constant******/
# define PI 3.14159  
# define POPSIZE 80
/****** the definition of user data*****/
# define LEFT -1
# define RIGHT 2
# define CHROMLENGTH 22

# define random(x) rand()%x

  const int MaxGeneration=200;
  const double Pc=0.6;
  const double Pm=0.001;

/***** the definition of data structure*****/
  struct individual
  { 
    char chrom[CHROMLENGTH+1];//基因 
    double x;   //自变量 
    double value;//目标函数值
    double fitness;//适应度
  };

/***** the definition of global variables*****/
  int generation;
  int best_index;
  int worst_index;
  struct individual bestindividual;     //局部最优个体
  struct individual worstindividual;    //局部最差个体
  struct individual currentbest;        //全局最优个体 
  struct individual population[POPSIZE];//种群 

/*****declaration of prototype 原型声明*****/
  void GenerateInitialPopulation (void);    //初始化种群 
  void GenerateNextPopulation (void);       //产生下一代种群 
  void EvaluatePopulation (void);           //评估 
  long DecodeChromosome (char *,int,int);   //对基因进行解码 
  void CalculateObjectValue (void);         //计算目标函数值 
  void CalculateFitnessValue (void);        //计算适应值 
  void FindBestAndWorstIndividual (void);   //寻找最优及最差个体 
  void PerformEvolution (void);             //进化 
  void SelectionOperator (void);            //选择 
  void CrossoverOperator (void);            //交叉 
  void MutationOperator (void);             //变异 
  void OutputTextReport (void);


/***** main program*****/
int main (void)
{ 
    generation=0;
    GenerateInitialPopulation ();       //调用初始群体函数  
    EvaluatePopulation ();          //第一次评估 
    while (generation<MaxGeneration)    //迭代一定代数 
    { 
        generation++;
        GenerateNextPopulation ();      //根据评估的结果来产生下一代 
        EvaluatePopulation ();          //对新一代种群进行评估 
        PerformEvolution ();            //进化 
        OutputTextReport ();
    }
    return 0;
}

/*****function:generation the first popolation初始化群体*****/
void GenerateInitialPopulation (void)
{ 
    int i,j;
    srand((unsigned)(time(NULL)));
    for (i=0;i<POPSIZE;i++)
    {
        for (j=0;j<CHROMLENGTH;j++)
        {
            population [i].chrom[j]=(random(10)<5)?'0':'1';
        }
        population [i].chrom[CHROMLENGTH]='\0';
    }
}

/*****function: generate the next generation产生新种群*****/
void GenerateNextPopulation (void)
{  
    SelectionOperator ();
    CrossoverOperator ();
    MutationOperator ();
}

/****function: evaluate population according to certain formula衡量群体*****/
void EvaluatePopulation (void)
{  
    CalculateObjectValue ();
    CalculateFitnessValue ();
    FindBestAndWorstIndividual ();
}

/*****function: to decode a binary chromosome into a decimal integer*****/
long DecodeChromosome (char *string,int point,int length)
{ 
    int i;
    long decimal=0L;
    char *pointer;
    for (i=0,pointer=string+point;i<length;i++,pointer++)
    { 
        decimal+=(*pointer-'0')<<(length-1-i);
    }
    return (decimal);
}

/***** function:to calculate object value f(x) = x sin(10πx) + 2.0 *****/
void CalculateObjectValue (void)
{ 
    int i;
    long temp;
    double x;
    /*** rosenbrock function***/
    for (i=0;i<POPSIZE;i++)
    {       
        temp=DecodeChromosome (population[i].chrom,0,CHROMLENGTH);
        x=(RIGHT-LEFT)*temp/(pow(2,CHROMLENGTH)-1.0)+LEFT;
        population[i].value=x*sin(10*PI*x)+2.0;
        population[i].x=x;
    }
}

/******function: to calculate fitness value *******/
void CalculateFitnessValue (void)
{ 
    int i;
    for(i=0;i<POPSIZE;i++)
    {
        population[i].fitness=population[i].value;
    }
}

/*****function to find out the best individual so far current generation*****/
void FindBestAndWorstIndividual (void)
{ 
    int i;
    double sum=0.0;
    /*** find out the best and worst individual of this generation***/
    bestindividual=population[0];
    worstindividual=population[0];
    for(i=1;i<POPSIZE;i++)
    {
        if (population[i].fitness>bestindividual.fitness)
        {bestindividual=population[i];best_index=i;}
        else if(population[i].fitness<worstindividual.fitness)
        {worstindividual=population[i];worst_index=i;}
        sum+=population[i].fitness;
    }
    /***find out the best individual so far***/
    if (generation==0){ currentbest=bestindividual;}
    else 
    { 
        if(bestindividual.fitness>currentbest.fitness) {currentbest=bestindividual;}
    }
}

/*****function:to perform evolution operation based on elitise mode. elitist model is to
       replace the worst individual of this generation by the current best one保留最优个体*****/
void PerformEvolution (void)
{ 
    if(bestindividual.fitness>currentbest.fitness){currentbest=population[best_index];}
    else{population[worst_index]=currentbest;}
}

/*****function: to reproduce a chromosome by roulette wheel seclection*****/
void SelectionOperator (void)
{ 
    int i,j,index;
    double p,sum=0.0;
    double cfitness[POPSIZE];  /*cumulative fitness value*/
    struct individual newpopulation[POPSIZE];
    /***calculate relative fitness***/
    for(i=0;i<POPSIZE;i++) {sum+=population[i].fitness;}
    for(i=0;i<POPSIZE;i++){cfitness[i]=population[i].fitness/sum;}
    /***calculate cumulative fitness***/
    for(i=1;i<POPSIZE;i++){cfitness[i]=cfitness[i-1]+cfitness[i];}
    /***selection operation***/
    for(i=0;i<POPSIZE;i++)
    {
        p=random(1000)/1000.0;
        index=0;
        while(p>cfitness[index]){index++;}
        newpopulation[i]=population[index];
    }
    for(i=0;i<POPSIZE;i++){population[i]=newpopulation[i];}
}

/*****function:crossover two chromosome by means of one-point crossover*****/
void CrossoverOperator (void)
{ 
    int i,j;
    int index[POPSIZE];
    int point,temp;
    double p;
    char ch;
    /***make a pair of individual randomly***/
    for(i=0;i<POPSIZE;i++){index[i]=i;}
    for(i=0;i<POPSIZE;i++)
    {
        point=random(POPSIZE-i);
        temp=index[i];
        index[i]=index[point+i];
        index[point+i]=temp;
    }
    /***one-point crossover operation***/
    for(i=0;i<POPSIZE-1;i+=2)
    {
        p=random(1000)/1000.0;
        if(p<Pc)
        { 
            point=random(CHROMLENGTH-1)+1;
            for(j=point;j<CHROMLENGTH;j++)
            { 
                ch=population[index[i]].chrom[j];
                population[index[i]].chrom[j]=population[index[i+1]].chrom[j];
                population[index[i+1]].chrom[j]=ch;
            }
        }
    }
}

/*****function: mutation of a chromosome*****/
void MutationOperator (void)
{ 
    int i,j;
    double p;
    /*** bit mutation***/
    for(i=0;i<POPSIZE;i++)
    {
        for(j=0;j<CHROMLENGTH;j++)
        {
            p=random(1000)/1000.0;
            if(p<Pm){population[i].chrom[j]=(population[i].chrom[j]=='0')?'1':'0';}
        }
    }
}

/*****function: output the results of current population*****/
void OutputTextReport (void)
{ 
    int i;
    double sum;
    double average;   /***average of population object value***/
    /*** calculate average object value***/
    sum=0.0;
    for(i=0;i<POPSIZE;i++){sum+=population[i].value;}
    average=sum/POPSIZE;
    /***print results of this population ***/
    printf("gen=%d, avg=%f, x=%f, best=%f ",generation,average,currentbest.x,currentbest.value);
    printf("chromosome=");
    for(i=0;i<CHROMLENGTH;i++){printf("%c",currentbest.chrom[i]);}
    printf("\n");
}