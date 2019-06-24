#ifndef UDMInterfMainMenuGrpCFH                  
#define UDMInterfMainMenuGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMInterfMainMenuGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMInterfMainMenuGrpCF();                                                           
   ~TDMInterfMainMenuGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
