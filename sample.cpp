#include <iostream>

#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <string>

#include <pthread.h>

#include <vector>



#define BUFFSIZE 1024



using namespace std;



vector<string> vPartionList;



void usage(void){

	fprintf(stderr,

		"usage:\n"

		"	DiskManager v1.00 05082016\n"

		"	DiskManager -r&              run DiskManager\n"

		"	DiskManager -h               show this help\n"

		"\n"

	);

}



string sCommand(const char *cCommand){

FILE *f = popen( cCommand, "r");

	string sFetchedString = "";

	char acFetchedChar[BUFFSIZE];

	while( fgets(acFetchedChar, BUFFSIZE, f){

	}

	pclose(f);

	sFetchedString(acFetchedChar);

	sFetchedString.resize(sFetchedString.size() -1);

	return sFetchedString;

}



int iGetPartionMounted(void){

	int iTotalPartion = 0;

	string sGetAllCurrentPartion = string("df -g | grep '/dev' | wc | awk '{print $1}'");

	iTotalPartion = atoi(sCommand(sGetAllCurrentPartion.c_str()));

//	cout << "Total Mounted Partition: " << iTotalPartion << endl;
//
//		return iTotalPartion;
//
//		}
//
//
//
//		void sGetPartionMemoryUsage(){
//
//		  FILE* fl;
//
//		    char* line = NULL;
//
//		      char* result = (char*) calloc(1, 1);
//
//		        size_t len = 0;
//
//
//
//		          fflush(NULL);
//
//		            string cmd = string("df -g | grep '/dev' | awk '{print $1}'");
//
//		              const char *command = cmd.c_str();
//
//		                fl = popen(command, "r");
//
//
//
//		                  while(getline(&line, &len, fl) != -1){
//
//		                      result = (char*) realloc(result, strlen(result) + strlen(line) + 1);
//
//		                          strncpy(result + strlen(result), line, strlen(line) + 1);
//
//		                              free(line);
//
//		                                  line = NULL;
//
//		                                     vPartionList.push_back(string(result));
//
//		                                        result = (char*) calloc(1,1);
//
//		                                          }
//
//		                                            fflush(fl);
//
//		                                              pclose(fl);
//
//		                                              }
//
//
//
//		                                              void ResourceMonitoring(void){
//
//		                                              	string sGetStorageValue = "";
//
//		                                              		string sMemoryLeft = "";
//
//		                                              			for(int i=0; i<=iGetPartionMounted(); i++){
//
//		                                              					sGetStorageValue = string("df -g | grep") + vPartionList[i] + string("| awk '{print $3}'");
//
//		                                              							sMemoryLeft = sCommand(sGetStorageValue.c_str());
//
//		                                              									if ( sMemoryLeft == "0" || sMemoryLeft == "0.0" || sMemoryLeft == "0.00") cout << "Partition " << vPartionList[i] << "is FULL, please allocate extra storage. . ." << endl;
//
//		                                              										}
//
//		                                              										}
//
//
//
//		                                              										void *ScheduleThread(void *ptr){
//
//		                                              											for(;;)
//
//		                                              												{
//
//		                                              												    	for(int s = 5; s > 0; s--)
//
//		                                              												    	    	{
//
//		                                              												    	    	//			cout << "schedule counter: " << s << endl;
//
//		                                              												    	    				sleep(1);	
//
//		                                              												    	    						}
//
//		                                              												    	    								ResourceMonitoring();
//
//		                                              												    	    								    }
//
//		                                              												    	    								    }
//
//
//
//		                                              												    	    								    void startSystemMonitoring(void)
//
//		                                              												    	    								    {
//
//		                                              												    	    								    	pthread_t thread;
//
//		                                              												    	    								    		int iret1;
//
//		                                              												    	    								    			iret1 = pthread_create( &thread, NULL, ScheduleThread,(void*) NULL);
//
//		                                              												    	    								    				if(iret1){
//
//		                                              												    	    								    						fprintf(stderr,"Error - pthread_create() return code: %d\n",iret1);
//
//		                                              												    	    								    								exit(EXIT_FAILURE);
//
//		                                              												    	    								    									}
//
//		                                              												    	    								    											pthread_join( thread1, NULL);
//
//		                                              												    	    								    											}
//
//
//
//		                                              												    	    								    											int main(int argc, char *argv[])
//
//		                                              												    	    								    											{
//
//		                                              												    	    								    												if ( argc <= 1 )
//
//		                                              												    	    								    													{
//
//		                                              												    	    								    															usage();
//
//		                                              												    	    								    																	return 0;
//
//		                                              												    	    								    																		}
//
//		                                              												    	    								    																			string argcomp = argv[1];
//
//		                                              												    	    								    																				if (argcomp == "--help"){
//
//		                                              												    	    								    																						usage();
//
//		                                              												    	    								    																								return 0;
//
//		                                              												    	    								    																									}
//
//
//
//		                                              												    	    								    																										if (argcomp == "-r"){		//Debug mode
//
//		                                              												    	    								    																												startSystemMonitoring();
//
//		                                              												    	    								    																														return 0;
//
//		                                              												    	    								    																															}
//
//		                                              												    	    								    																																
//
//		                                              												    	    								    																																	return 0;
//
//		                                              												    	    								    																																		/* non-cout operation
//
//		                                              												    	    								    																																			ofstream   fout("/dev/null");
//
//		                                              												    	    								    																																				cout.rdbuf(fout.rdbuf()); // redirect 'cout' to a 'fout'
//
//		                                              												    	    								    																																				   	vthreads(argc);
//
//		                                              												    	    								    																																				   	    exit(EXIT_SUCCESS);
//
//		                                              												    	    								    																																				   	    	*/
//
//
//
//		                                              												    	    								    																																				   	    	}
