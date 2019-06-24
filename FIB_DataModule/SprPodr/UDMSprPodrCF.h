#ifndef UDMSprPodrCFH                  
#define UDMSprPodrCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprPodrCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprPodrCF();                                                           
   ~TDMSprPodrCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
