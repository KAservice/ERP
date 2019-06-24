#ifndef UFormaSpiskaSprSkladCFH                  
#define UFormaSpiskaSprSkladCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaSpiskaSprSkladCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaSpiskaSprSkladCF();                                                           
   ~TFormaSpiskaSprSkladCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
