#ifndef UDMGurLogCFH                  
#define UDMGurLogCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMGurLogCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMGurLogCF();                                                           
   ~TDMGurLogCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
