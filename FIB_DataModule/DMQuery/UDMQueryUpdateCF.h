#ifndef UDMQueryUpdateCFH                  
#define UDMQueryUpdateCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMQueryUpdateCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMQueryUpdateCF();                                                           
   ~TDMQueryUpdateCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
