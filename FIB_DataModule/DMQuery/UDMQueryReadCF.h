#ifndef UDMQueryReadCFH                  
#define UDMQueryReadCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMQueryReadCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMQueryReadCF();                                                           
   ~TDMQueryReadCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
