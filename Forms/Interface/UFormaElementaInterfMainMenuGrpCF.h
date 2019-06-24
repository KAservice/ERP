#ifndef UFormaElementaInterfMainMenuGrpCFH                  
#define UFormaElementaInterfMainMenuGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaInterfMainMenuGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaInterfMainMenuGrpCF();                                                           
   ~TFormaElementaInterfMainMenuGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
