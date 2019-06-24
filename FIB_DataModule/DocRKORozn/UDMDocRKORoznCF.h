#ifndef UDMDocRKORoznCFH                  
#define UDMDocRKORoznCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMDocRKORoznCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMDocRKORoznCF();                                                           
   ~TDMDocRKORoznCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
