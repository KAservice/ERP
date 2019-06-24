#ifndef UFormaSpiskaSprProduceCFH                  
#define UFormaSpiskaSprProduceCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprProduceCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprProduceCF();                                                           
   ~TFormaSpiskaSprProduceCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
