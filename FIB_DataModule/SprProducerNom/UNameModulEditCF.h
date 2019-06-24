#ifndef UNameModulEditCFH                  
#define UNameModulEditCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TNameModulEditCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TNameModulEditCF();                                                           
   ~TNameModulEditCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
