#ifndef UFormaKKTOperationCFH                  
#define UFormaKKTOperationCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaKKTOperationCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaKKTOperationCF();                                                           
   ~TFormaKKTOperationCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
