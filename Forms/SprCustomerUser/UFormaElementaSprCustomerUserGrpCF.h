#ifndef UFormaElementaSprCustomerUserGrpCFH                  
#define UFormaElementaSprCustomerUserGrpCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaElementaSprCustomerUserGrpCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaElementaSprCustomerUserGrpCF();                                                           
   ~TFormaElementaSprCustomerUserGrpCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
