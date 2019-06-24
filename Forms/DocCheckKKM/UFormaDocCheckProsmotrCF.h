#ifndef UFormaDocCheckProsmotrCFH                  
#define UFormaDocCheckProsmotrCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TFormaDocCheckProsmotrCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TFormaDocCheckProsmotrCF();                                                           
   ~TFormaDocCheckProsmotrCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
