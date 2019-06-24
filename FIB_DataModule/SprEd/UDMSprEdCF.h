#ifndef UDMSprEdCFH                  
#define UDMSprEdCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMSprEdCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMSprEdCF();                                                           
   ~TDMSprEdCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
