package org.adman.kmp.tdlib

object TDLib {
    init {
        System.loadLibrary("tdjsonjni")
    }

    /**
     * Creates a new TDLib client instance.
     *
     * @return The client ID.
     */
    external fun tdCreateClientId(): Int

    /**
     * Sends a request to TDLib.
     *
     * @param clientId The client ID.
     * @param request The JSON-serialized request.
     */
    external fun tdSend(clientId: Int, request: String)

    /**
     * Receives updates from TDLib.
     *
     * @param timeout The maximum number of seconds allowed for waiting for updates.
     * @return The JSON-serialized response, or null if no updates are available within the timeout.
     */
    external fun tdReceive(timeout: Double): String?

    /**
     * Executes a TDLib request synchronously.
     *
     * @param request The JSON-serialized request.
     * @return The JSON-serialized response, or null if an error occurred.
     */
    external fun tdExecute(request: String): String?
}