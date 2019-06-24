#ifndef UREM_FormaDocZTrebCFH                  
#define UREM_FormaDocZTrebCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TREM_FormaDocZTrebCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TREM_FormaDocZTrebCF();                                                           
   ~TREM_FormaDocZTrebCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
