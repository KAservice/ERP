#ifndef UFormaElementaSprCustomerMainMenuGrpCFH                  
#define UFormaElementaSprCustomerMainMenuGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprCustomerMainMenuGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprCustomerMainMenuGrpCF();                                                           
   ~TFormaElementaSprCustomerMainMenuGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
