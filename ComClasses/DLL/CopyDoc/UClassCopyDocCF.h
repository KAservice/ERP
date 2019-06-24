#ifndef UClassCopyDocCFH                  
#define UClassCopyDocCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TClassCopyDocCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TClassCopyDocCF();                                                           
   ~TClassCopyDocCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
