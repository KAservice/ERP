#ifndef UHOT_FormaGurAllDocCFH                  
#define UHOT_FormaGurAllDocCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class THOT_FormaGurAllDocCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   THOT_FormaGurAllDocCF();                                                           
   ~THOT_FormaGurAllDocCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
