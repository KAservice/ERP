#ifndef UDMGurAllDocCFH                  
#define UDMGurAllDocCFH                  
#include "GlobalInterface.h"            
//---------------------------------------------------------------
class TDMGurAllDocCF : public IkanClassFactory                                 
{                                                                             
public:                                                                       
   TDMGurAllDocCF();                                                           
   ~TDMGurAllDocCF();                                                          
   int NumRefs;                                                               
   virtual int kanQueryInterface(REFIID id_interface, void ** ppv);     
	  virtual int kanAddRef(void);                                         
	  virtual int kanRelease(void);                                        
   virtual int kanCreateInstance(REFIID id_interface, void ** ppv); 
};                                                                     
//---------------------------------------------------------------
#endif                                                                 
