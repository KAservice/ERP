#ifndef UDMGurDocPerCFH                  
#define UDMGurDocPerCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMGurDocPerCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMGurDocPerCF();                                                           
   ~TDMGurDocPerCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
